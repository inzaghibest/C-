// zxp_queue.h
#ifndef ZXP_QUEUE_H_H
#define ZXP_QUEUE_H_H
// 循环队列实现
#define QUEUE_SIZE 10
template <class T>
class CCirQueue
{
private:
	T m_array[QUEUE_SIZE];
	int front, rear; // 头尾指针
public:
	CCirQueue();
	~CCirQueue(){}
	void EnQueue(T x); // 进队
	T DeQueue(); // 出队
	T GetQueue(); // 获取队头元素
	bool Empty();
};
template <class T>
CCirQueue<T>::CCirQueue()
{
	front = rear = 0;
}

template <class T>
void CCirQueue<T>::EnQueue(T x)
{
	if ( (rear + 1) % QUEUE_SIZE == front)
	{
		throw "队列满";
	}
	rear = (rear + 1) % QUEUE_SIZE;
	m_array[rear] = x;
}

template <class T>
T CCirQueue<T>::DeQueue()
{
	if (front == rear)
	{
		throw "队列空";
	}
	front = (front + 1)%QUEUE_SIZE;
	return m_array[front];
}

template <class T>
T CCirQueue<T>::GetQueue()
{
	if (front == rear)
	{
		throw "队列空";
	}
	int n = (front + 1) % MAX_SIZE;
	return m_array[n];
}

template <class T>
bool CCirQueue<T>::Empty()
{
	return front == rear ? true : false;
}

// 链队列
/*template <class T>
struct Node
{
	Node* pNextNode;
	int value;
};*/
template <class T>
class CLinkQueue
{
private:
	Node<T>* m_pFront;
	Node<T>* m_pRear; // 队头,队尾指针
public:
	CLinkQueue();
	~CLinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	bool Empty();
};

template <class T>
CLinkQueue<T>::CLinkQueue()
{
	m_pFront = NULL;
	m_pRear = NULL;
}

template <class T>
void CLinkQueue<T>::EnQueue(T x)
{
	Node<T>* s = new Node<T>;
	s->m_value = x;
	s->pNextNode = NULL;
	if (m_pFront == NULL)
	{
		m_pFront = s;
	}
	if (m_pRear == NULL)
	{
			m_pRear = s;
	}else
	{
		m_pRear->pNextNode = s;
		m_pRear = s;
	}
}

template <class T>
T CLinkQueue<T>::DeQueue()
{
	if (m_pFront == m_pRear && m_pFront == NULL && m_pRear == NULL)
	{
		throw "队列为空";
	}
	Node<T> * s = m_pFront;
	int value = m_pFront->m_value;
	if (m_pFront == m_pRear)
	{
		m_pFront = NULL;
		m_pRear = NULL;
	}else
	{
		m_pFront = m_pFront->pNextNode;
	}
	delete s;
	return value;
}

template <class T>
T CLinkQueue<T>::GetQueue()
{
	if (m_pFront == m_pRear && m_pFront == NULL && m_pRear == NULL)
	{
		throw "队列为空";
	}
	return m_pFront->m_value;
}

template <class T>
bool CLinkQueue<T>::Empty()
{
	return ((m_pFront == m_pRear) && (m_pFront == NULL) && (m_pRear == NULL)); 
}

template <class T>
CLinkQueue<T>::~CLinkQueue()
{
	while (m_pFront != NULL)
	{
		DeQueue();
	}
}
#endif // ZXP_QUEUE_H_H