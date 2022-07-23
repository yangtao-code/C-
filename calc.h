#ifndef CALC_H
#define CALC_H

#include "linkqueue.h"
#include "linkstack.h"
#include <string.h>
#include <stdlib.h>


//中缀表达式转后缀表达式
void mid_to_post(const char *expr, LinkStack *stack, LinkQueue *queue);
//判断字符串是数字还是数学符号
bool is_digit(char op);

void push_operator(char *op, LinkStack *stack, LinkQueue *queue);

int get_priority(char op);

int calc_post(LinkStack *stack, LinkQueue *queue);
//计算后缀表达式
char *basic_calculate(char *left, char *right, char op);
//实现字符串转数字的功能
int str_to_num(char *str);
//实现数字转字符串的功能
char *num_to_str(char *str, int num);

#endif