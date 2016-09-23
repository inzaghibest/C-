// YingKe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// 题目:C++多态用父类指针,引用,对象哪些可以实现
// 解答:父类指针或者用父类对象的引用引用子类对象

// 引申:虚函数表:
/* 函数表
对C++ 了解的人都应该知道虚函数（Virtual Function）是通过一张虚函数表（Virtual Table）来实现的。
简称为V-Table。在这个表中，主是要一个类的虚函数的地址表，这张表解决了继承、覆盖的问题，保证其
容真实反应实际的函数。这样，在有虚函数的类的实例中这个表被分配在了这个实例的内存中，所以，当
我们用父类的指针来操作一个子类的时候，这张虚函数表就显得由为重要了，它就像一个地图一样，指明了
实际所应该调用的函数。
这里我们着重看一下这张虚函数表。C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置
（这是为了保证取到虚函数表的有最高的性能——如果有多层继承或是多重继承的情况下）。 这意味着我们
[通过对象实例的地址得到这张虚函数表，然后就可以遍历其中函数指针，并调用相应的函数]。*/
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
// 一般继承（无虚函数覆盖）
// 1）虚函数按照其声明顺序放于表中。
// 2）父类的虚函数在子类的虚函数前面。
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
	// 一般继承（有虚函数覆盖）
	virtual void funcA()
	{
		printf("I'm Derive Vritual Func funcA()\r\n");
	}
};

// 多重继承（无虚函数覆盖）
// 1）  每个父类都有自己的虚表。
// 2）  子类的成员函数被放到了第一个父类的表中。（所谓的第一个父类是按照声明顺序来判断的）
// 这样做就是为了解决不同的父类类型的指针指向同一个子类实例，而能够调用到实际的函数。

// 多重继承（有虚函数覆盖）
void Test1()
{
	Derive derive;
	printf("虚函数表地址%x\r\n", *(int*)&derive);
	int i = 0;
	while (1)
	{
		// 在上面这个图中，我在虚函数表的最后多加了一个结点，这是虚函数表的结束结点，就像字符串的
		// 结束符“/0”一样，其标志了虚函数表的结束。这个结束标志的值在不同的编译器下是不同的。在
		// WinXP+VS2003下，这个值是NULL。而在Ubuntu 7.10 + Linux 2.6.22 + GCC 4.1.3下，这个值是如果
		// 1，表示还有下一个虚函数表，如果值是0，表示是最后一个虚函数表。
		if (((int*)*(int*)(&derive))[i] == NULL)
		{
			break;
		}
		pFunc pfunc = (pFunc)(((int*)*(int*)(&derive))[i]);
		printf("第%d个虚函数地址%x\r\n", i+1, pfunc);
		printf("调用这个虚函数...");
		pfunc();
		i++;
	}
	//printf("第一个虚函数地址%x\r\n", (int*)*(int*)&base);
	//printf("第一个虚函数地址%x\r\n", *(&base));
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

