// StringError.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <assert.h>
#include <malloc.h>
// 试题1
void func1()
{
	char str[10];
	char* pStr = "0123456789";
	strcpy(str, pStr); // 导致数组越界
	printf("%s\r\n", str);
}
// 试题2
void func2()
{
	char str1[10], str2[10];
	for (int i = 0; i<10; i++)
	{
		// 1.由于数组没有字符'\0'结尾,所以字符数组不能在数组内结束
		str1[i] = 'a';
	}
	// 2.strcpy工作方式,直到str1遇到'\0'停止复制,所以复制结束位置不确定
	// 即复制的字节数据有不确定性
	strcpy(str2,str1);
	printf(str2);
}

// 试题3
void func3(char* str1)
{
	char str[10];
	// strlen的工作方式,不包含'\0'字符,所以有可能导致strcpy越界
	// 应改为strlen(str1) < 10
	if (strlen(str1) <= 10)
	{
		strcpy(str,str1);
		printf(str);
	}
}

// 试题4
// 给出strcpy函数的实现
// 1.链式操作,将目的字符串返回
// 2.源字符串声明为const,防止意外改变
// 3.判断传入指针不为NULL
char* my_strcpy(char* szDest, const char* szSrc)
{
	if (szDest == NULL || szSrc == NULL)
	{
		return NULL;
	}
	char* szRetrun = szDest;
	while ((*szDest++ = *szSrc++) != '\0');
	return szRetrun;
}
// strlen函数
int my_strlen(const char* str)
{
	assert(str != NULL);
	int nLen = 0;
	while ((*str++) != '\0')
	{
		nLen++;
	}
	return nLen;
}
/* 上述三题主要考察:
1. 字符串以'\0'结尾
2. 对数据越界的敏感度把握
3. 库函数strcpy的工作方式,以及能否实现一个标准的strcpy函数
*/
// 试题4
void GetMemory(char** p)
{
	*p = (char*)malloc(100);
	if (*p == NULL) // 对申请内存失败情况的判断
	{
		// ...申请失败处理
	}
}

void TestGetMemory()
{
	char* str = NULL;
	// 形参无法改变实参,导致指针还是非法,且在GetMemory内分配的内存没有释放
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	if(str != NULL) 
	{
		free(str);
		str = NULL; // 释放内存后将野指针置为NULL
	}
}

char* GetMemory2()
{
	char p[] = "hello world";
	return p; // 返回局部变量的指针, 返回后改变量已经不存在了
}

void TestGetMemory2()
{
	char* str = NULL;
	str = GetMemory2();
	printf(str);
}
/* 上述试题主要考察:
1.指针的理解
2.变量的生存期及作用范围
3.良好的动态内存申请和释放习惯
*/

// 下段程序有什么错误?
swap(int* p1, int* p2)
{
	//int *p; // 野指针
	//*p = *p1; // 非法内存访问
	int p;
	p = *p1;
	*p2 = *p1;
	*p1 = *p2;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//char szBuffer[] ="0123456789";
	//func3(szBuffer);
	TestGetMemory2();
	getchar();
	return 0;
}

