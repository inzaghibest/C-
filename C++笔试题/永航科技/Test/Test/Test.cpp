// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
/* 分析 
在类中，如果什么都没有，则类占用1个字节，一旦类中有其他的占用空间成员，
则这1个字节就不在计算之内，如一个类只有一个int则占用4字节而不是5字节。
如果只有成员函数，则还是只占用1个字节，因为类函数不占用空间
虚函数因为存在一个虚函数表，需要4个字节，数据成员对象如果为指针则为4字节，
注意有字节对齐，如果为13字节，则进位到16字节空间。*/
//#pragma pack(1) // 指定结构体不对齐
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
// 结构体在内存中对齐原则
// 1.元素按定义顺序放入到内存中,从首地址开始，每个元素都认为是按照自己大小来划分的内存，也就是说
// 每个元素总是以自己宽度的倍数开始.
// 2.结构体的大小是最大元素大小的整数倍.
struct Node
{
	int a;
	char b;
	short c;
	char d;
};
//#pragma pack()
// 返回局部变量的指针
const char* getString()
{
	return "hello world";
}
class B:public A
{
};

// 题目描述：求一个一维数组向右旋转K个位置后的结果。比如，一维数组{1, 2, 3, 4, 5}，当k = 2时，
// 求得的结果为{4, 5, 1, 2, 3}。要求常数级空间复杂度，允许修改原有数组。
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

// 三次反转,第一次反转整个数组,第二次翻转前k个,第三次翻转后k个
void RoteArrayK(int array[], int nCount, int k)
{
	if (array == NULL || nCount == 0 || k <0 || k > nCount)
	{
		return;
	}
	// 翻转整个数组
	ReserveArray(array, nCount, 0, nCount-1);
	// 翻转前k个
	ReserveArray(array, k, 0, k-1);
	// 翻转后k个
	ReserveArray(array, nCount, k, nCount-1);
}

// 1.不用库函数将字符串转换为数字
// "34567" 输出 34561
long ConvertStringToInt(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	int nSig = 1;
	int Temp = 0;
	// 如果字符串带有符号
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
	// 1. 含有虚函数的类的大小问题以及引申的结构体内存对齐问题
	/*printf("sizeof(A):%d\r\n", sizeof(A));
	printf("sizeof(B):%d\r\n", sizeof(B));
	printf("sizeof(Node):%d\r\n", sizeof(Node));
	printf("sizeof(int):%d\r\n", sizeof(int));
	printf("sizeof(char):%d\r\n", sizeof(char));
	printf("sizeof(short):%d\r\n", sizeof(short));*/
	// 2.进制 或
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

	// map的三种数据插入方法
	map<int, char*> myMap;
	// 1.下标的方法
	/*myMap[0] = "hello";
	myMap[1] = "world";
	myMap[2] = "mfc";*/
	// 2.insert
	//myMap.insert(pair<int, char*>(0, "hello"));
	// 3.insert
	//myMap.insert(map<int, char*>::value_type (0, "hello"));
	// 三种插入方式的区别
	// insert方式:用insert函数插入数据，在数据的插入上涉及到集合的唯一性这个概念，
	// 即当map中有这个关键字时，insert操作是插入数据不了的
	myMap.insert(pair<int, char*>(0, "hello"));
	myMap.insert(pair<int, char*>(1, "world"));
	// 用pair来验证数据是否插入成功
	pair<map<int, char*>::iterator, bool> insertIterator;
	insertIterator = myMap.insert(pair<int, char*>(1, "mfc"));
	if (insertIterator.second != true)
	{
		printf("插入失败\r\n");
	}
	// 数组是可以覆盖的
	myMap[0] = "h11";

	for (map<int, char*>::iterator it = myMap.begin(); it!=myMap.end(); it++)
	{
		printf("%s\r\n", it->second);
	}

	getchar();
	return 0;
}

