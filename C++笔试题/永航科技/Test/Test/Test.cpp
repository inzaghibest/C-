// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
/* ���� 
�����У����ʲô��û�У�����ռ��1���ֽڣ�һ��������������ռ�ÿռ��Ա��
����1���ֽھͲ��ڼ���֮�ڣ���һ����ֻ��һ��int��ռ��4�ֽڶ�����5�ֽڡ�
���ֻ�г�Ա����������ֻռ��1���ֽڣ���Ϊ�ຯ����ռ�ÿռ�
�麯����Ϊ����һ���麯������Ҫ4���ֽڣ����ݳ�Ա�������Ϊָ����Ϊ4�ֽڣ�
ע�����ֽڶ��룬���Ϊ13�ֽڣ����λ��16�ֽڿռ䡣*/
//#pragma pack(1) // ָ���ṹ�岻����
class A
{
public:
	virtual void func(){}
	virtual void func1(){}
//	void func1(){}
private:
	int a;
	char b;
	short c;
	char d;
};
// �ṹ�����ڴ��ж���ԭ��
// 1.Ԫ�ذ�����˳����뵽�ڴ���,���׵�ַ��ʼ��ÿ��Ԫ�ض���Ϊ�ǰ����Լ���С�����ֵ��ڴ棬Ҳ����˵
// ÿ��Ԫ���������Լ���ȵı�����ʼ.
// 2.�ṹ��Ĵ�С�����Ԫ�ش�С��������.
struct Node
{
	int a;
	char b;
	short c;
	char d;
};
//#pragma pack()
// ���ؾֲ�������ָ��
const char* getString()
{
	return "hello world";
}
class B:public A
{
};

// ��Ŀ��������һ��һά����������תK��λ�ú�Ľ�������磬һά����{1, 2, 3, 4, 5}����k = 2ʱ��
// ��õĽ��Ϊ{4, 5, 1, 2, 3}��Ҫ�������ռ临�Ӷȣ������޸�ԭ�����顣
bool ReserveArray(int array[], int nCount, int nStart, int nEnd)
{
	if (array == NULL && nCount)
	{
		return false;
	}
	if (nStart > nCount || nStart < 0)
	{
		return false;
	}
	if (nEnd > nCount || nEnd < 0)
	{
		return false;
	}
	while (nStart < nEnd)
	{
		int Temp = array[nStart];
		array[nStart] = array[nEnd];
		array[nEnd] = Temp;
		nStart++;
		nEnd--;
	}
	return true;

}

// ���η�ת,��һ�η�ת��������,�ڶ��η�תǰk��,�����η�ת��k��
void RoteArrayK(int array[], int nCount, int k)
{
	if (array == NULL || nCount == 0 || k <0 || k > nCount)
	{
		return;
	}
	// ��ת��������
	ReserveArray(array, nCount, 0, nCount-1);
	// ��תǰk��
	ReserveArray(array, k, 0, k-1);
	// ��ת��k��
	ReserveArray(array, nCount, k, nCount-1);
}

// 1.���ÿ⺯�����ַ���ת��Ϊ����
// "34567" ��� 34561
long ConvertStringToInt(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	int nSig = 1;
	int Temp = 0;
	// ����ַ������з���
	if (*str == '-')
	{
		nSig = -1;
		str++;
	}
	if (*str == '+')
	{
		nSig = 1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			break;
		}
		Temp = Temp*10 + (*str - '0');
		str++;
	}
	Temp*=nSig;
	return Temp;
}

// 
int _tmain(int argc, _TCHAR* argv[])
{
	// 1. �����麯������Ĵ�С�����Լ�����Ľṹ���ڴ��������
	/*printf("sizeof(A):%d\r\n", sizeof(A));
	printf("sizeof(B):%d\r\n", sizeof(B));
	printf("sizeof(Node):%d\r\n", sizeof(Node));
	printf("sizeof(int):%d\r\n", sizeof(int));
	printf("sizeof(char):%d\r\n", sizeof(char));
	printf("sizeof(short):%d\r\n", sizeof(short));*/
	// 2.���� ��
	/*int a = -3;
	//int b = 0x17;
	printf("%02X",(a|b));
	string str1 = getString();
	printf("%s\r\n", str1);*/
	/*int array[] = {1,2,3,4,5};
	RoteArrayK(array, sizeof(array)/sizeof(int), 5);
	for (int i = 0; i<(sizeof(array)/sizeof(int)); i++)
	{
		printf("%d, ", array[i]);
	}*/

	//char szBuffer[] = "-12392";
	//long nArray = ConvertStringToInt(szBuffer);
	//printf("%d\r\n", nArray);

	// map���������ݲ��뷽��
	map<int, char*> myMap;
	// 1.�±�ķ���
	/*myMap[0] = "hello";
	myMap[1] = "world";
	myMap[2] = "mfc";*/
	// 2.insert
	//myMap.insert(pair<int, char*>(0, "hello"));
	// 3.insert
	//myMap.insert(map<int, char*>::value_type (0, "hello"));
	// ���ֲ��뷽ʽ������
	// insert��ʽ:��insert�����������ݣ������ݵĲ������漰�����ϵ�Ψһ��������
	// ����map��������ؼ���ʱ��insert�����ǲ������ݲ��˵�
	myMap.insert(pair<int, char*>(0, "hello"));
	myMap.insert(pair<int, char*>(1, "world"));
	// ��pair����֤�����Ƿ����ɹ�
	pair<map<int, char*>::iterator, bool> insertIterator;
	insertIterator = myMap.insert(pair<int, char*>(1, "mfc"));
	if (insertIterator.second != true)
	{
		printf("����ʧ��\r\n");
	}
	// �����ǿ��Ը��ǵ�
	myMap[0] = "h11";

	for (map<int, char*>::iterator it = myMap.begin(); it!=myMap.end(); it++)
	{
		printf("%s\r\n", it->second);
	}

	getchar();
	return 0;
}

