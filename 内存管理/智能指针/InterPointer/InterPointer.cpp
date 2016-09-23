// InterPointer.cpp : 定义控制台应用程序的入口点。
// 智能指针简介
/* C++智能指针是行为类似于指针的类对象。它使用设计模式中的代理模式，代理了原始“裸”指针的行为，
为指针添加了更多更有用的特性。
C++引入异常机制后，智能指针由一种技巧升级为一种非常重要的技术，因为如果没有智能指针，程序员必须
保证new对象能在正确的时机delete，四处编写异常捕获代码释放资源，而智能指针则可以在退出作用域时—
—不管是正常离开或是因异常离开——总调用delete来析构在堆栈上动态分配的对象。
因为C++异常处理的真正功能在于它具有为异常抛掷前构造的所有局部对象(那么智能指针对象也适用)自动调
用析构函数的能力（C++异常机制不仅仅在于它能够处理各种不同类型的异常）。所以在异常退出智能指针对
象作用域时，总能由C++异常机制调用析构函数释放在堆栈上动态分配的对象。
当然，正常退出对象（智能指针对象也属于此列）作用域也会自动调用析构函数释放在堆栈上动态分配的对象。
由此可知，将“裸”指针包装成智能指针对象可以实现动态分配的内存对象的自动释放。
而且C++智能指针对象可以像原指针那样直接使用运算符，如赋值运算符'='，指针运算符'->'，解引用运算符
'*'。这点可以从”shared_ptr智能指针--shared_ptr模板类摘要“部分可以印证。*/

#include "stdafx.h"
#include <Windows.h>
//#include <memory>

template <class T>
class Auto_Ptr;

// 智能指针引用计数类
template <class T>
class Ref_Ptr
{
	friend class Auto_Ptr<T>;
private:
	T* m_pTtr; // 实际的指针
	size_t m_RefCount; // 引用计数
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template <class T>
Ref_Ptr<T>::Ref_Ptr(T* p)
{
	m_pTtr = p;
	m_RefCount = 1;
	printf("Ref_Ptr() 构造函数调用!\r\n");
}

template <class T>
Ref_Ptr<T>::~Ref_Ptr()
{
	if (m_pTtr)
	{
		printf("~Ref_Ptr() 析构函数函数调用");
		delete m_pTtr;
		m_RefCount =0;
	}
	m_pTtr = NULL;
}

// 智能指针对象
template <class T>
class Auto_Ptr
{
private:
	Ref_Ptr<T>* m_pRef; // 引用计数
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();
	// 重载运算=,将左对象引用计数-1,并判断是否delete;将右对象+1;
	Auto_Ptr<T> & operator = (Auto_Ptr& other);
	// 重载指针操作*,->
	T& operator *();
	T* operator ->();
	// 拷贝构造函数,引用计数+1
	Auto_Ptr(Auto_Ptr<T>& other);
};
template <class T>
Auto_Ptr<T>::Auto_Ptr()
{
	m_pRef = NULL;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(T* p)
{
	m_pRef = new Ref_Ptr<T>(p);
	printf("Auto_Ptr(T* p) 构造函数调用\r\n");
}

template <class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other)
{
	this->m_pRef = other.m_pRef;
	++(m_pRef->m_RefCount);
	printf("Auto_Ptr(& other) 拷贝构造函数被调用,当前引用计数%d", this->m_pRef->m_RefCount);
}

template <class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other)
{
	// 将右操作对象引用计数+1
	++(other.m_pRef->m_RefCount);

	// 由于左操作对象指向了新对象,需要将操作数-1;
	// 同时也防止了自赋值的方式.
	// 首先要判断这个对象是否已经指向了其他对象,这个很重要!防止左指针对象为null的情况.
	if (this->m_pRef)
	{
		if (--(this->m_pRef->m_RefCount) == 0)
		{
			delete this->m_pRef;
		}
	}

	this->m_pRef = other.m_pRef;
	printf("operator = 被调用,当前引用计数%d", this->m_pRef->m_RefCount);
	return *this;
}

template <class T>
T& Auto_Ptr<T>::operator *()
{
	return *(m_pRef->m_pTtr);
}

template <class T>
T* Auto_Ptr<T>::operator->()
{
	return (m_pRef->m_pTtr);
}

template <class T>
Auto_Ptr<T>::~Auto_Ptr()
{
	printf("~Auto_Ptr() 析构函数被调用\r\n");
	if ((--m_pRef->m_RefCount) == 0)
	{
		printf("删除\r\n");
		delete m_pRef;
		m_pRef = NULL;
	}
	if (m_pRef)
	{
			printf("当前引用计数:%d", m_pRef->m_RefCount);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Auto_Ptr<int>* pPtr = NULL;
	{
		Auto_Ptr<int> g_ptr;
		{
			// 声明一个ptr1智能指针,并测试*运算符
			Auto_Ptr<int> ptr1(new int(4));
			printf("%d\r\n", *ptr1);
			// 将生存期小的ptr1赋值给生存期更大的g_ptr;
			g_ptr = ptr1;
		}
		// new int(4)并没有销毁,因为引用计数还有1个
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2; // 此时将g_ptr指向一个新的智能指针对象,原引用计数-1,销毁了.(可以看到赋值左减的重要性)
		// 这个测试的是指向局部智能指针对象的智能对象指针,果然是有问题的;
		// 相当于指向局部变量地址的指针.
		Auto_Ptr<int>* pPtr = &ptr2;
		printf("%d\r\n", *(*pPtr));
	}
	Sleep(2000);
	// 错误,局部对象的指针已经释放!!!!
	//printf("%d\r\n", *(*pPtr));
	getchar();
	return 0;
}
	/*{
		Auto_Ptr<int> ptr(new int(3));
		ptr = ptr;
		printf("%d\r\n", *ptr);
	}*/
	//printf("1");
	/*std::tr1::shared_ptr<int> sp(new int(10));
	printf("%d, ", *sp);
	*sp = 3;
	printf("%d, ", *sp);
	printf("%s\r\n", (sp.unique() == true ? "唯一" : "不唯一"));
	std::tr1::shared_ptr<int> sp2;
	sp2 = sp;
	printf("%s\r\n", (sp.unique() == true ? "唯一" : "不唯一"));
	printf("引用计数%d,   引用计数%d\r\n", sp.use_count(), sp2.use_count());
	*sp2 = 100;
	printf("%d\r\n", *sp);*/
//	getchar();
//	return 0;
//}

