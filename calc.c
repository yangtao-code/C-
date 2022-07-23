#include "calc.h"

int calc_post(LinkStack *stack, LinkQueue *queue)
{
    char tmp[32];
    while (!Queue_Empty(queue))
    {
        strcpy(tmp, Get_Queue_Top(queue));
        DeQueue(queue);
        if (!is_digit(tmp[0]))
        {
            char right[32];
            strcpy(right, Get_Stack_Top(stack));
            DeStack(stack);
            char left[32];
            strcpy(left, Get_Stack_Top(stack));
            DeStack(stack);
            char *ret = basic_calculate(left, right, tmp[0]);
            EnStack(stack, ret);
        }
        else
        {
            EnStack(stack, tmp);
        }
    }
    char tmp1[32];
    strcpy(tmp1, Get_Stack_Top(stack));
    DeStack(stack);
    int ret = str_to_num(tmp1);
    return ret;
}

char *basic_calculate(char *left, char *right, char op)
{
    int left1 = str_to_num(left);
    int right1 = str_to_num(right);
    int tmp = 0;
    switch (op)
    {
    case '*':
        tmp = left1 * right1;
        break;
    case '/':
        tmp = left1 / right1;
        break;
    case '+':
        tmp = left1 + right1;
        break;
    case '-':
        tmp = left1 - right1;
        break;
    default:
        break;
    }
    char *ret = num_to_str(left, tmp);
    return ret;
}

int str_to_num(char *str)
{
    int ret = 0;
    while (*str != '\0')
    {
        ret = ret * 10 + *str - 48;
        str++;
    }
    return ret;
}

char *num_to_str(char *str, int num)
{
    char *ret = str;
    while (num != 0)
    {
        *str = num % 10 + 48;
        str++;
        num = num / 10;
    }
    *str = '\0';
    int len = strlen(ret);
    int left = 0;
    int right = len - 1;
    char tmp;
    while (left < right)
    {
        tmp = ret[left];
        ret[left] = ret[right];
        ret[right] = tmp;
        left++;
        right--;
    }
    return ret;
}

void mid_to_post(const char *expr, LinkStack *stack, LinkQueue *queue)
{
    char date[32] = {0};
    char *tmp = date;
    char str[2] = {0};
    for (int i = 0; i < strlen(expr); i++)
    {
        char c = expr[i];

        if (is_digit(c))
        {
            *tmp++ = c;
        }
        else
        {
            str[0] = c;
            if (Stack_Empty(stack))
            {
                *tmp = '\0';
                EnStack(stack, str);
                EnQueue(queue, date);
                tmp = date;
            }
            else
            {
                *tmp = '\0';
                EnQueue(queue, date);
                tmp = date;
                push_operator(str, stack, queue);
            }
        }
    }
    *tmp = '\0';
    EnQueue(queue, date);
    while (!Stack_Empty(stack))
    {
        EnQueue(queue, Get_Stack_Top(stack));
        DeStack(stack);
    }
}

void push_operator(char *op, LinkStack *stack, LinkQueue *queue)
{
    while (!Stack_Empty(stack))
    {
        char *top_op = Get_Stack_Top(stack);
        if (get_priority(op[0]) > get_priority(top_op[0]))
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