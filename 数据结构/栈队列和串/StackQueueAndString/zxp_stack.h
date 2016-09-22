#ifndef _ZXP_STACK_H_H
#define _ZXP_STACK_H_H
// 由于顺序栈比较简单,我们实现一个共享栈,及两个栈共享一片存储空间,提高效率
#define  MAX_SIZE 1024
template <class T>
class CBothStack
{
private:
	T m_array[MAX_SIZE];
	int m_top1;
	int m_top2;
public:
	CBothStack();
	~CBothStack(){}
	void Push(int i, T value);
	T Pop(int i);
	bool Empty(int i);
	T GetTop(int i);
	void PrintStack();
};

template <class T>
CBothStack<T>::CBothStack()
{
	m_top1 = -1;
	m_top2 = MAX_SIZE;
}

template <class T>
void CBothStack<T>::Push(int i, T value)
{
	// 判断栈是否已满
	if((m_top2 - m_top1) == 1)
	{
		throw "栈满";
	}
	if (i == 1)
	{
		m_array[++m_top1] = value;
	}else
	{
		m_array[--m_top2] = value;
	}
}

template<class T>
T CBothStack<T>::Pop(int i)
{
	if (i == 1)
	{
		if (m_top1 == - 1)
		{
			throw "栈1没有元素";
		}
		T value = m_array[m_top1--];
		return value;
	}else
	{
		if (m_top2 == MAX_SIZE)
		{
			throw "栈2没有元素";
		}
		T value = m_array[m_top2++];
		return value;
	}
}

template <class T>
T CBothStack<T>::GetTop(int i)
{
	if (i == 1)
	{
		if (m_top1 == - 1)
		{
			throw "栈1没有元素";
		}
		T value = m_array[m_top1];
		return value;
	}else
	{
		if (m_top2 == MAX_SIZE)
		{
			throw "栈2没有元素";
		}
		T value = m_array[m_top2];
		return value;
	}
}

template <class T>
bool CBothStack<T>::Empty(int i)
{
	if (i == 1)
	{
		return (m_top1 == -1 ? true : false);
	}else
	{
		return (m_top2 == MAX_SIZE ? true : false);
	}
}

template<class T>
void CBothStack<T>::PrintStack()
{
	if (!Empty(1))
	{
		printf("栈1:");
		int top = m_top1;
		while (top >= 0)
		{
			printf("%d, ", m_array[top--]);
		}
	}
	if (!Empty(2))
	{
		printf("栈2:");
		int top = m_top2;
		while (top < MAX_SIZE)
		{
			printf("%d, ", m_array[top++]);
		}
	}
}

// 链栈
template <class T>
struct Node
{
	Node* pNextNode;
	T m_value;
};
template <class T>
class CLinkStack
{
private:
	Node<T>* m_top;
public:
	CLinkStack();
	~CLinkStack();
	void Push(T value);
	T Pop();
	bool Empty();
	T GetTop();
};

template <class T>
CLinkStack<T>::CLinkStack()
{
	m_top = NULL;
}

template <class T>
CLinkStack<T>::~CLinkStack()
{
	if (m_top != NULL)
	{
		Node<T>* s = m_top;
		while (s != NULL)
		{
			printf("1,");
			Node<T>* r = s;
			s = s->pNextNode;
			delete r;
		}
	}
	m_top = NULL;
}

template <class T>
void CLinkStack<T>::Push(T value)
{
	Node<T>* s = new Node<T>;
	s->m_value = value;
	s->pNextNode = m_top;
	m_top = s;
}

template <class T>
T CLinkStack<T>::Pop()
{
	if (m_top != NULL)
	{
		int value = m_top->m_value;
		Node<T>* s = m_top;
		m_top = m_top->pNextNode;
		delete s;
		return value;
	}
	throw "链栈无元素";
}

template <class T>
T CLinkStack<T>::GetTop()
{
	if (m_top != NULL)
	{
		return m_top->m_value;
	}
	throw "链栈无元素";
}

template <class T>
bool CLinkStack<T>::Empty()
{
	return m_top == NULL ? true : false;
}

#endif // _ZXP_STACK_H_H