#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include"my_string.h"
#include<assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* ret1 = str1;
	char* ret2 = str2;
	while (*str1)
	{
		ret1 = str1;
		str2 = ret2;
		while (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return ret1;
		}
		str1 = ret1 + 1;
	}
	return NULL;
}

/**
 * .把src字符串加到des字符串后面
 * 
 * \param des
 * \param src
 * \return 
 */
char* my_strcat(char* des, const char* src)
{
	assert(des != NULL);
	assert(src != NULL);
	char* ret = des;
	while (*des)
	{
		des++;
	}
	while (*des++=*src++)
	{
		;
	}
	return ret;
}

/**
 * .比较两个字符串
 * 
 * \param str1	
 * \param str2
 * \return 
 */
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			break;
		}
	}
	return *str1 - *str2;
}

/*
 * .把src字符串拷贝到des字符串
 * 
 * \param des
 * \param src
 * \return 
 */
char* my_strcpy(char* des, const char* src)
{
	assert(des != NULL);
	assert(src != NULL);
	char* ret = des;
	while (*src)
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
	return ret;
}

/**
 * .求一个字符串的长度
 * 
 * \param str 字符串的首地址
 * \return 返回字符串的长度
 */
int my_strlen(const char* str)
{
	assert(str != NULL);
	int len = 0;
	while (*str++)
	{

		len++;
	}
	return len;
}

/**
 * .实现数组的拷贝
 * 
 * \param des	被拷贝的地址
 * \param src	
 * \param count
 * \return 
 */
void* my_memmove(void* des, const void* src, size_t count)
{
	assert(des != NULL);
	assert(des != NULL);
	void* ret = des;
	while (count--)
	{
		if ((char*)des - (char*)src >= 0)
		{
			*((char*)des+count) = *( (char*)src+count );
		}
		else
		{
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}
