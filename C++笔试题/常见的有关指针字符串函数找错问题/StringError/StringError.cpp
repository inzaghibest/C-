// StringError.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <assert.h>
#include <malloc.h>
// ����1
void func1()
{
	char str[10];
	char* pStr = "0123456789";
	strcpy(str, pStr); // ��������Խ��
	printf("%s\r\n", str);
}
// ����2
void func2()
{
	char str1[10], str2[10];
	for (int i = 0; i<10; i++)
	{
		// 1.��������û���ַ�'\0'��β,�����ַ����鲻���������ڽ���
		str1[i] = 'a';
	}
	// 2.strcpy������ʽ,ֱ��str1����'\0'ֹͣ����,���Ը��ƽ���λ�ò�ȷ��
	// �����Ƶ��ֽ������в�ȷ����
	strcpy(str2,str1);
	printf(str2);
}

// ����3
void func3(char* str1)
{
	char str[10];
	// strlen�Ĺ�����ʽ,������'\0'�ַ�,�����п��ܵ���strcpyԽ��
	// Ӧ��Ϊstrlen(str1) < 10
	if (strlen(str1) <= 10)
	{
		strcpy(str,str1);
		printf(str);
	}
}

// ����4
// ����strcpy������ʵ��
// 1.��ʽ����,��Ŀ���ַ�������
// 2.Դ�ַ�������Ϊconst,��ֹ����ı�
// 3.�жϴ���ָ�벻ΪNULL
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
// strlen����
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
/* ����������Ҫ����:
1. �ַ�����'\0'��β
2. ������Խ������жȰ���
3. �⺯��strcpy�Ĺ�����ʽ,�Լ��ܷ�ʵ��һ����׼��strcpy����
*/
// ����4
void GetMemory(char** p)
{
	*p = (char*)malloc(100);
	if (*p == NULL) // �������ڴ�ʧ��������ж�
	{
		// ...����ʧ�ܴ���
	}
}

void TestGetMemory()
{
	char* str = NULL;
	// �β��޷��ı�ʵ��,����ָ�뻹�ǷǷ�,����GetMemory�ڷ�����ڴ�û���ͷ�
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	if(str != NULL) 
	{
		free(str);
		str = NULL; // �ͷ��ڴ��Ұָ����ΪNULL
	}
}

char* GetMemory2()
{
	char p[] = "hello world";
	return p; // ���ؾֲ�������ָ��, ���غ�ı����Ѿ���������
}

void TestGetMemory2()
{
	char* str = NULL;
	str = GetMemory2();
	printf(str);
}
/* ����������Ҫ����:
1.ָ������
2.�����������ڼ����÷�Χ
3.���õĶ�̬�ڴ�������ͷ�ϰ��
*/

// �¶γ�����ʲô����?
swap(int* p1, int* p2)
{
	//int *p; // Ұָ��
	//*p = *p1; // �Ƿ��ڴ����
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

