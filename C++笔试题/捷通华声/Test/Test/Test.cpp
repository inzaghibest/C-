// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
// 1.�����������
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

/*1) malloc��free��C++/C���Եı�׼�⺯����new/delete��C++������������Ƕ�������
���붯̬�ڴ���ͷ��ڴ档
2) ���ڷ��ڲ��������͵Ķ�����ԣ�����maloc/free�޷����㶯̬�����Ҫ�󡣶����ڴ�
����ͬʱҪ�Զ�ִ�й��캯��������������֮ǰҪ�Զ�ִ����������������malloc/free��
�⺯������������������ڱ���������Ȩ��֮�ڣ����ܹ���ִ�й��캯������������������
ǿ����malloc/free��
���C++������Ҫһ������ɶ�̬�ڴ����ͳ�ʼ�������������new���Լ�һ�����������
���ͷ��ڴ湤���������delete��ע��new/delete���ǿ⺯����
���ǲ�Ҫ��ͼ��malloc/free����ɶ�̬������ڴ����Ӧ����new/delete�������ڲ���
�����͵ġ�����û�й����������Ĺ��̣������Ƕ���malloc/free��new/delete�ǵȼ۵ġ�
3) ��Ȼnew/delete�Ĺ�����ȫ������malloc/free��ΪʲôC++����malloc/free��̭�����أ�
������ΪC++���򾭳�Ҫ����C��������C����ֻ����malloc/free����̬�ڴ档
�����free�ͷš�new�����Ķ�̬���󡱣���ô�ö������޷�ִ���������������ܵ��³������
�����delete�ͷš�malloc����Ķ�̬�ڴ桱�����Ҳ�ᵼ�³���������Ǹó���Ŀɶ���
�ܲ����new/delete�������ʹ�ã�malloc/freeҲһ����*/

//4// ʵ��һ�������Ķ�̬���� 
//�����Ǵ��룬�����Ӧ���� 
const int ARRAT_GROWUP = 10; 
//����ṹ�嶨�� 
struct ArrayStruct
{ 
	int iCurMaxElementCount; //��ǰ�������������Ԫ�صĸ��� 
	int iCurElementCount;  //��ǰԪ���� 
	int *pHead;    //ָ��ͷ�� 
public:
	ArrayStruct()
	{
		printf("���캯��������");
	}
	ArrayStruct(ArrayStruct& other)
	{
		printf("�������캯������\r\n");
		iCurElementCount = other.iCurElementCount;
		iCurMaxElementCount = other.iCurMaxElementCount;

		//memcpy(pHead, other.pHead, sizeof(int) * iCurMaxElementCount);
	}
	ArrayStruct& operator = (ArrayStruct& other)
	{
		printf("�����=����\r\n");
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
//���ܣ�����һ�����飬����Ϊ���Ԫ�ظ��� 
//������int iStartElementCount �����ʼ����С 
//���أ��ɹ�����ָ�룬���򷵻�NULL
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
//���ܣ����������һ��Ԫ�أ����Ԫ�س�������Array_Init������iStartElementCount����ʱ��
//�뿼�������Ӧ�����Լٶ�һ������ARRAY_GROWUP��Ԫ������������Ҫ��֤���ڴ�������Ϊ
//���Դ�ţ�Ҳ����˵�����ģ�������һ�������������� 
//������ArrayStruct *pArray  Ҫ���������ṹ��ָ�� 
//const int iAppendElement Ҫ���ӵ�Ԫ��
//���أ��ɹ�ʱ����true��ʧ��ʱ����false(10��) 
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
	// ��Ҫ���·����ڴ�
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
// ���ܣ�ɾ��ָ��������Ԫ�أ�Ҫ��֤Ԫ�����ڴ�Ϊ���Բ������� 
// ������ArrayStruct *pArray  Ҫ���������ṹ��ָ�� 
// const int iRemovedIndex Ҫɾ����Ԫ������ 
// ���أ��ɹ�ʱ����true��ʧ��ʱ����false��10�֣�
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
//���ܣ�����ָ��������Ԫ�� 
//������const ArrayStruct *pArray Ҫ���������ṹ��ָ�� 
//  const int iIndex Ҫȡ������ֵ 
//  int & iReturn �ɹ�ʱ��ֵ 
//���أ��ɹ�Ϊtrueʧ��Ϊfalse  
bool Array_GetElement(const ArrayStruct *pArray,const int iIndex,int & iReturn)
{
	return true;
}  
//���ܣ�ɾ��һ������ 
//�������Լ�����
//���أ��ޣ�10�֣� 
void Array_Release(/*�����������ϲ���*/)
{ } 
// �������ڵ㶨������
struct Node
{
	Node* pChild[2];
	int m_i;
};
// ��Ҷ����
int get_TreeNodeCount(Node* pHead)
{
	if (pHead == NULL)
	{
		return 0;
	}
	return 1+get_TreeNodeCount(pHead->pChild[0]) + get_TreeNodeCount(pHead->pChild[1]);
}
// 666��ƻ��,10������,��η����ÿ�����1-666��ƻ����ֱ�Ӹ��������Ӿ�����.
// 1,2,4,8,16,32,64,128,256,155.(�ó������ʵ��?)
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
	// ������new������pa���ڴ�,�����malloc,����ʲô����,new��malloc������:
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
	//����һ�������ĸ�ֵ�� 
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

