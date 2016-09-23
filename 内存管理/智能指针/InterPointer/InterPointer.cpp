// InterPointer.cpp : �������̨Ӧ�ó������ڵ㡣
// ����ָ����
/* C++����ָ������Ϊ������ָ����������ʹ�����ģʽ�еĴ���ģʽ��������ԭʼ���㡱ָ�����Ϊ��
Ϊָ������˸�������õ����ԡ�
C++�����쳣���ƺ�����ָ����һ�ּ�������Ϊһ�ַǳ���Ҫ�ļ�������Ϊ���û������ָ�룬����Ա����
��֤new����������ȷ��ʱ��delete���Ĵ���д�쳣��������ͷ���Դ��������ָ����������˳�������ʱ��
�������������뿪�������쳣�뿪�����ܵ���delete�������ڶ�ջ�϶�̬����Ķ���
��ΪC++�쳣�����������������������Ϊ�쳣����ǰ��������оֲ�����(��ô����ָ�����Ҳ����)�Զ���
������������������C++�쳣���Ʋ������������ܹ�������ֲ�ͬ���͵��쳣�����������쳣�˳�����ָ���
��������ʱ��������C++�쳣���Ƶ������������ͷ��ڶ�ջ�϶�̬����Ķ���
��Ȼ�������˳���������ָ�����Ҳ���ڴ��У�������Ҳ���Զ��������������ͷ��ڶ�ջ�϶�̬����Ķ���
�ɴ˿�֪�������㡱ָ���װ������ָ��������ʵ�ֶ�̬������ڴ������Զ��ͷš�
����C++����ָ����������ԭָ������ֱ��ʹ����������縳ֵ�����'='��ָ�������'->'�������������
'*'�������Դӡ�shared_ptr����ָ��--shared_ptrģ����ժҪ�����ֿ���ӡ֤��*/

#include "stdafx.h"
#include <Windows.h>
//#include <memory>

template <class T>
class Auto_Ptr;

// ����ָ�����ü�����
template <class T>
class Ref_Ptr
{
	friend class Auto_Ptr<T>;
private:
	T* m_pTtr; // ʵ�ʵ�ָ��
	size_t m_RefCount; // ���ü���
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template <class T>
Ref_Ptr<T>::Ref_Ptr(T* p)
{
	m_pTtr = p;
	m_RefCount = 1;
	printf("Ref_Ptr() ���캯������!\r\n");
}

template <class T>
Ref_Ptr<T>::~Ref_Ptr()
{
	if (m_pTtr)
	{
		printf("~Ref_Ptr() ����������������");
		delete m_pTtr;
		m_RefCount =0;
	}
	m_pTtr = NULL;
}

// ����ָ�����
template <class T>
class Auto_Ptr
{
private:
	Ref_Ptr<T>* m_pRef; // ���ü���
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();
	// ��������=,����������ü���-1,���ж��Ƿ�delete;���Ҷ���+1;
	Auto_Ptr<T> & operator = (Auto_Ptr& other);
	// ����ָ�����*,->
	T& operator *();
	T* operator ->();
	// �������캯��,���ü���+1
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
	printf("Auto_Ptr(T* p) ���캯������\r\n");
}

template <class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other)
{
	this->m_pRef = other.m_pRef;
	++(m_pRef->m_RefCount);
	printf("Auto_Ptr(& other) �������캯��������,��ǰ���ü���%d", this->m_pRef->m_RefCount);
}

template <class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other)
{
	// ���Ҳ����������ü���+1
	++(other.m_pRef->m_RefCount);

	// �������������ָ�����¶���,��Ҫ��������-1;
	// ͬʱҲ��ֹ���Ը�ֵ�ķ�ʽ.
	// ����Ҫ�ж���������Ƿ��Ѿ�ָ������������,�������Ҫ!��ֹ��ָ�����Ϊnull�����.
	if (this->m_pRef)
	{
		if (--(this->m_pRef->m_RefCount) == 0)
		{
			delete this->m_pRef;
		}
	}

	this->m_pRef = other.m_pRef;
	printf("operator = ������,��ǰ���ü���%d", this->m_pRef->m_RefCount);
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
	printf("~Auto_Ptr() ��������������\r\n");
	if ((--m_pRef->m_RefCount) == 0)
	{
		printf("ɾ��\r\n");
		delete m_pRef;
		m_pRef = NULL;
	}
	if (m_pRef)
	{
			printf("��ǰ���ü���:%d", m_pRef->m_RefCount);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Auto_Ptr<int>* pPtr = NULL;
	{
		Auto_Ptr<int> g_ptr;
		{
			// ����һ��ptr1����ָ��,������*�����
			Auto_Ptr<int> ptr1(new int(4));
			printf("%d\r\n", *ptr1);
			// ��������С��ptr1��ֵ�������ڸ����g_ptr;
			g_ptr = ptr1;
		}
		// new int(4)��û������,��Ϊ���ü�������1��
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2; // ��ʱ��g_ptrָ��һ���µ�����ָ�����,ԭ���ü���-1,������.(���Կ�����ֵ�������Ҫ��)
		// ������Ե���ָ��ֲ�����ָ���������ܶ���ָ��,��Ȼ���������;
		// �൱��ָ��ֲ�������ַ��ָ��.
		Auto_Ptr<int>* pPtr = &ptr2;
		printf("%d\r\n", *(*pPtr));
	}
	Sleep(2000);
	// ����,�ֲ������ָ���Ѿ��ͷ�!!!!
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
	printf("%s\r\n", (sp.unique() == true ? "Ψһ" : "��Ψһ"));
	std::tr1::shared_ptr<int> sp2;
	sp2 = sp;
	printf("%s\r\n", (sp.unique() == true ? "Ψһ" : "��Ψһ"));
	printf("���ü���%d,   ���ü���%d\r\n", sp.use_count(), sp2.use_count());
	*sp2 = 100;
	printf("%d\r\n", *sp);*/
//	getchar();
//	return 0;
//}

