// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
// 1.下题的输出结果
class A
{
public:
	int m_a;
public:
	A(int a = 0):m_a(a){cout<<"create class A"<<m_a<<endl;}
	virtual ~A(){cout<<"delete class A"<<endl;}
	void func()
	{
		cout<<"A func()"<<endl;
	}
};
class B:public A
{
public:
	int m_b;
public:
	B(int b = 0):m_b(b),A(b){cout<<"create class B"<<m_b<<endl;}
	virtual ~B()
	{
		cout<<"delete class B"<<endl;
	}

};

/*1) malloc与free是C++/C语言的标准库函数，new/delete是C++的运算符。它们都可用于
申请动态内存和释放内存。
2) 对于非内部数据类型的对象而言，光用maloc/free无法满足动态对象的要求。对象在创
建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于malloc/free是
库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务
强加于malloc/free。
因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，以及一个能完成清理
与释放内存工作的运算符delete。注意new/delete不是库函数。
我们不要企图用malloc/free来完成动态对象的内存管理，应该用new/delete。由于内部数
据类型的“对象”没有构造与析构的过程，对它们而言malloc/free和new/delete是等价的。
3) 既然new/delete的功能完全覆盖了malloc/free，为什么C++不把malloc/free淘汰出局呢？
这是因为C++程序经常要调用C函数，而C程序只能用malloc/free管理动态内存。
如果用free释放“new创建的动态对象”，那么该对象因无法执行析构函数而可能导致程序出错。
如果用delete释放“malloc申请的动态内存”，结果也会导致程序出错，但是该程序的可读性
很差。所以new/delete必须配对使用，malloc/free也一样。*/

//4// 实现一个整数的动态数组 
//下面是代码，完成相应函数 
const int ARRAT_GROWUP = 10; 
//数组结构体定义 
struct ArrayStruct
{ 
	int iCurMaxElementCount; //当前数组最大能容纳元素的个数 
	int iCurElementCount;  //当前元素数 
	int *pHead;    //指针头部 
public:
	ArrayStruct()
	{
		printf("构造函数被调用");
	}
	ArrayStruct(ArrayStruct& other)
	{
		printf("拷贝构造函数调用\r\n");
		iCurElementCount = other.iCurElementCount;
		iCurMaxElementCount = other.iCurMaxElementCount;

		//memcpy(pHead, other.pHead, sizeof(int) * iCurMaxElementCount);
	}
	ArrayStruct& operator = (ArrayStruct& other)
	{
		printf("运算符=调用\r\n");
		iCurElementCount = other.iCurElementCount;
		iCurMaxElementCount = other.iCurMaxElementCount;
		//memcpy(pHead, other.pHead, sizeof(int) * iCurMaxElementCount);
		return *this;
	}
	void Print()
	{
		if (pHead != NULL)
		{
			for (int i = 0; i<iCurElementCount; i++)
			{
				printf("%d\r\n", pHead[i]);
			}
		}
	}
};  
//功能：生成一个数组，参数为最初元素个数 
//参数：int iStartElementCount 数组初始化大小 
//返回：成功返回指针，否则返回NULL
ArrayStruct* Array_init(int iStartElementCount)
{
	if (iStartElementCount == 0)
	{
		return NULL;
	}
	ArrayStruct* pArrayStruct = new ArrayStruct;
	if(pArrayStruct == NULL)
		return NULL;
	pArrayStruct->iCurElementCount = 0;
	pArrayStruct->iCurMaxElementCount = iStartElementCount;
	pArrayStruct->pHead = new int[iStartElementCount];
	if (pArrayStruct->pHead == NULL)
	{
		delete pArrayStruct;
		return NULL;
	}
	return pArrayStruct;
}
//功能：向数组添加一个元素，如果元素超过上述Array_Init函数的iStartElementCount参数时，
//请考虑如何适应。可以假定一次增加ARRAY_GROWUP个元素容量，但是要保证在内存中数据为
//线性存放（也就是说连续的，像数组一样，而不是链表） 
//参数：ArrayStruct *pArray  要处理的数组结构体指针 
//const int iAppendElement 要增加的元素
//返回：成功时返回true，失败时返回false(10分) 
bool Array_AddElement(ArrayStruct *pArray, const int iAppendElement) 
{
	if (pArray == NULL)
	{
		pArray = Array_init(ARRAT_GROWUP);
		if (pArray == NULL)
		{
			return false;
		}
		*(pArray->pHead) = iAppendElement;
		return true;
	}
	// 需要重新分配内存
	if (pArray->iCurElementCount == pArray->iCurMaxElementCount)
	{
		pArray->iCurElementCount += 1;
		pArray->iCurMaxElementCount += ARRAT_GROWUP;
		int nResize = pArray->iCurMaxElementCount; 
		pArray->pHead = (int*)realloc(pArray->pHead, sizeof(int) * nResize);
		if (pArray->pHead == NULL)
		{
			return false;
		}
		(pArray->pHead)[pArray->iCurElementCount - 1] = iAppendElement;
	}else
	{
		(pArray->pHead)[pArray->iCurElementCount] = iAppendElement;
		pArray->iCurElementCount += 1;
	}
	return true;
}
// 功能：删除指定索引的元素，要保证元素在内存为线性不间隔存放 
// 参数：ArrayStruct *pArray  要处理的数组结构体指针 
// const int iRemovedIndex 要删除的元素索引 
// 返回：成功时返回true，失败时返回false（10分）
bool Array_RemoveElement(ArrayStruct *pArray,const int iRemovedIndex) 
{
	if (pArray == NULL || pArray->pHead == NULL)
	{
		return false;
	}
	if (iRemovedIndex >= pArray->iCurElementCount)
	{
		return false;
	}
	for (int i = iRemovedIndex; i<pArray->iCurElementCount; i++)
	{
		if (i == pArray->iCurElementCount - 1)
		{
			(pArray->pHead[i]) = 0;
			return true;
		}
		(pArray->pHead)[i] = (pArray->pHead)[i+1];
	}
	return true;
}
//功能：返回指定索引的元素 
//参数：const ArrayStruct *pArray 要处理的数组结构体指针 
//  const int iIndex 要取得索引值 
//  int & iReturn 成功时的值 
//返回：成功为true失败为false  
bool Array_GetElement(const ArrayStruct *pArray,const int iIndex,int & iReturn)
{
	return true;
}  
//功能：删除一个数组 
//参数：自己定义
//返回：无（10分） 
void Array_Release(/*请在这里填上参数*/)
{ } 
// 二叉树节点定义如下
struct Node
{
	Node* pChild[2];
	int m_i;
};
// 求叶子数
int get_TreeNodeCount(Node* pHead)
{
	if (pHead == NULL)
	{
		return 0;
	}
	return 1+get_TreeNodeCount(pHead->pChild[0]) + get_TreeNodeCount(pHead->pChild[1]);
}
// 666个苹果,10个箱子,如何放能让客人买1-666个苹果都直接给若干箱子就行了.
// 1,2,4,8,16,32,64,128,256,155.(用程序如何实现?)
int PutApple(int k)
{
	if (k == 1)
	{
		return 1;
	}
	return 2*PutApple(k-1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 1; i<11; i++)
	{
		printf("%d\r\n", PutApple(i));
	}
	//A* pa = new B();
	//delete pa;
	// 上面用new开辟了pa的内存,如何用malloc,会有什么问题,new与malloc的区别:
	/*A* pa = new B();
	pa->func();
	printf("%d\r\n", pa->m_a);
	//free(pa);*/
	//A* pa = (A*)malloc(sizeof(B));
	//pa->A();
	/*int i=10; 
	int *pint1=new int(10);
	int *pint2=new int[10];
	int aint[10];  
	//计算一下下面四个值： 
	printf("sizeof(i) = %d, sizeof(new int(10)) = %d, sizeof(new int[10]) = %d, sizeof(aint[10]) = %d", sizeof(i), sizeof(pint1), sizeof(pint2), sizeof(aint));*/

	//int* pa = NULL;
	//int* pb = new int(3);
	//memcpy(pa, pb, sizeof(int));
	//printf("%d\r\n", *pa);
	/*if ()
	{
	}*/
	ArrayStruct* pArrayStruct = Array_init(5);
	for (int i = 0; i<10; i++)
	{
		Array_AddElement(pArrayStruct, i);
	}
	pArrayStruct->Print();
	getchar();
	return 0;
}

