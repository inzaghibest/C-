// YingKe.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// ��Ŀ:C++��̬�ø���ָ��,����,������Щ����ʵ��
// ���:����ָ������ø����������������������

// ����:�麯����:
/* ������
��C++ �˽���˶�Ӧ��֪���麯����Virtual Function����ͨ��һ���麯����Virtual Table����ʵ�ֵġ�
���ΪV-Table����������У�����Ҫһ������麯���ĵ�ַ�����ű����˼̳С����ǵ����⣬��֤��
����ʵ��Ӧʵ�ʵĺ����������������麯�������ʵ��������������������ʵ�����ڴ��У����ԣ���
�����ø����ָ��������һ�������ʱ�������麯������Ե���Ϊ��Ҫ�ˣ�������һ����ͼһ����ָ����
ʵ����Ӧ�õ��õĺ�����
�����������ؿ�һ�������麯����C++�ı�����Ӧ���Ǳ�֤�麯�����ָ������ڶ���ʵ������ǰ���λ��
������Ϊ�˱�֤ȡ���麯���������ߵ����ܡ�������ж��̳л��Ƕ��ؼ̳е�����£��� ����ζ������
[ͨ������ʵ���ĵ�ַ�õ������麯����Ȼ��Ϳ��Ա������к���ָ�룬��������Ӧ�ĺ���]��*/
typedef void (*pFunc)(void);
class Base
{
	virtual void funcA()
	{
		printf("I'm Base funcA\r\n");
	}
	virtual void funcB()
	{
		printf("I'm Base funcB\r\n");
	}
	virtual void funcC()
	{
		printf("I'm Base funcC\r\n");
	}
};
// һ��̳У����麯�����ǣ�
// 1���麯������������˳����ڱ��С�
// 2��������麯����������麯��ǰ�档
class Derive:public Base
{
public:
	virtual void funcG()
	{
		printf("I'm Derive funcG\r\n");
	}
	virtual void FuncH()
	{
		printf("I'm Derive FuncH\r\n");
	}
	// һ��̳У����麯�����ǣ�
	virtual void funcA()
	{
		printf("I'm Derive Vritual Func funcA()\r\n");
	}
};

// ���ؼ̳У����麯�����ǣ�
// 1��  ÿ�����඼���Լ������
// 2��  ����ĳ�Ա�������ŵ��˵�һ������ı��С�����ν�ĵ�һ�������ǰ�������˳�����жϵģ�
// ����������Ϊ�˽����ͬ�ĸ������͵�ָ��ָ��ͬһ������ʵ�������ܹ����õ�ʵ�ʵĺ�����

// ���ؼ̳У����麯�����ǣ�
void Test1()
{
	Derive derive;
	printf("�麯�����ַ%x\r\n", *(int*)&derive);
	int i = 0;
	while (1)
	{
		// ���������ͼ�У������麯������������һ����㣬�����麯����Ľ�����㣬�����ַ�����
		// ��������/0��һ�������־���麯����Ľ��������������־��ֵ�ڲ�ͬ�ı��������ǲ�ͬ�ġ���
		// WinXP+VS2003�£����ֵ��NULL������Ubuntu 7.10 + Linux 2.6.22 + GCC 4.1.3�£����ֵ�����
		// 1����ʾ������һ���麯�������ֵ��0����ʾ�����һ���麯����
		if (((int*)*(int*)(&derive))[i] == NULL)
		{
			break;
		}
		pFunc pfunc = (pFunc)(((int*)*(int*)(&derive))[i]);
		printf("��%d���麯����ַ%x\r\n", i+1, pfunc);
		printf("��������麯��...");
		pfunc();
		i++;
	}
	//printf("��һ���麯����ַ%x\r\n", (int*)*(int*)&base);
	//printf("��һ���麯����ַ%x\r\n", *(&base));
	//pFunc pfunc = (pFunc)*(int*)*(int*)&base;
	//pfunc();
	
}
/*class A
{
public:
	virtual void func()
	{
		printf("I'm a A class\r\n");
	}
};
class B:public A
{
public:
	void func()
	{
		printf("I'm a B class\r\n");
	}
};*/
void func1()
{
	printf("func1()");
};
void func2()
{
	printf("func2()");
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*A a;
	B b;
	a = b;
	a.func();
	A& Ya = b;
	Ya.func();
	A* pa = new B;
	pa->func();*/
	//pFunc array[] = {func1, func2};
	//printf("%x\r\n", (int*)array);
	//printf("%x\r\n", (int*)*array);
	//pFunc func = (pFunc)(*array);
	//func();
	//printf("%d\r\n", *pA);
	Test1();
	//test2();
	getchar();
	return 0;
}

