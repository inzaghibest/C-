#ifndef ZXP_LINKLIST_H_H
#define ZXP_LINKLIST_H_H
#include <string>
using namespace std;
class CError
{
private:
	string m_strError;
public:
	CError(string strErr):m_strError(strErr)
	{

	}
	string GetErrorMsg()
	{
		return m_strError;
	}
};
template <class T>
struct Node
{
	Node* pNextNode;
	T m_value;
};

struct elem
{
	int coef; // 系数
	int exp; // 指数
};

template <class T>
class CLinkList
{
private:
	Node<T>* m_pHead;
	int m_nLength; // 单链表长度
	// 一元多项式求和
	friend void Add(CLinkList<elem> & A, CLinkList<elem>& B);
public:
	friend void Circle(int n, int m);
	CLinkList();
	// 初始化含有n个元素,值为value的单链表
	CLinkList(int n, T value);
	~CLinkList();
	// 求单链表长度
	int GetLength();
	// 删除单链表的第i个结点,返回删除结点的值
	T Delete(int i);
	// 在单链表中第i个位置插入值为x的元素
	void Insert(int i, T x);
	// 返回值为value的序号
	int GetValue(T value);
	// 返回第i个元素的值
	T GetLocate(int i);
	// 单链表遍历
	void PrintList();
	// 单链表逆序
	void Reverse();
	// 将当链表转换成环,此方法使用之后,只能使用Delete(i)方法;此方法是为了解决约瑟夫环问题
	void Ring();
	// 递归实现单链表逆序
	//void RecursionForReverse();
};
template <class T>
CLinkList<T>::CLinkList()
{
	m_pHead = NULL;
}

template <class T>
CLinkList<T>::CLinkList(int n, T value)
{
	// 头插法建立单链表
	/*for (int i = 0; i<n; i++)
	{
		Node* pNode = new Node<T>;
		pNode->m_value = value;
		pNode->pNextNode = pHead;
		pHead = pNode;
	}*/
	// 尾插法建立单链表
	m_pHead = new Node<T>;
	m_pHead->m_value = value++;
	m_pHead->pNextNode = NULL;
	Node<T>* pTail = m_pHead;
	for (int i = 1; i<n; i++)
	{
		Node<T>* pWork = new Node<T>;
		pWork->m_value = value++;
		pWork->pNextNode = NULL;
		pTail->pNextNode = pWork;
		pTail = pWork;
	}
}

template <class T>
int CLinkList<T>::GetLength()
{
	if (m_pHead == NULL)
	{
		return 0;
	}
	int i = 0;
	Node<T>* r = m_pHead;
	while (r != NULL)
	{
		i++;
		r = r->pNextNode;
	}
	// 删除改结点
	return i;
}

template <class T>
T CLinkList<T>::Delete(int i)
{
	if (i == 0)
	{
		CError error("删除位置异常");
		throw error;
	}
	// 头指针删除
	if (i == 1)
	{
		Node<T>* r = m_pHead;
		m_pHead = m_pHead->pNextNode;
		int nValue = r->m_value;
		delete r;
		return nValue;
	}
	Node<T>* r = m_pHead;
	Node<T>* prev = m_pHead;
	while (--i && r != NULL)
	{
		prev = r;
		r = r->pNextNode;
	}
	if (r == NULL)
	{
		CError error("链表未初始化");
		throw error;
	}
	// r是要删除的结点,prev是前置结点
	int value = r->m_value;
	prev->pNextNode = r->pNextNode;
	delete r;
	return value;
}

template <class T>
void CLinkList<T>::Insert(int i, T x)
{
	if (i == 0)
	{
		CError error("插入位置异常!");
		throw  error;
	}
	if (m_pHead == NULL)
	{
		m_pHead = new Node<T>;
		m_pHead->m_value = x;
		m_pHead->pNextNode = NULL;
		return;
	}
	// 寻找插入结点
	Node<T>* r = m_pHead;
	Node<T>* prev = m_pHead;
	while (--i && r!=NULL)
	{
		prev = r;
		r=r->pNextNode;
	}
	if (r == NULL) // 此种情况认为插在队尾
	{
		r = new Node<T>;
		r->m_value = x;
		r->pNextNode = NULL;
		prev->pNextNode = r;
		return;
	}
	// 如果是在头结点插入,将头指针指向这个结点,这个结点下一个为原来的头指针
	if (r == m_pHead)
	{
		Node<T>* pNode = new Node<T>;
		pNode->m_value = x;
		pNode->pNextNode = r;
		m_pHead = pNode;
		return;
	}

	Node<T>* pNode = new Node<T>;
	pNode->m_value = x;
	pNode->pNextNode = r;
	prev->pNextNode = pNode;
	return;
}

template <class T>
T CLinkList<T>::GetLocate(int i)
{
	Node<T>* pNode = m_pHead;
	while (--i && pNode != NULL)
	{
		pNode = pNode->pNextNode;
	}
	if (pNode == NULL)
	{
		CError error("查找位置非法");
		throw error;
	}
	int nValue = pNode->m_value;
	return nValue;
}

template <class T>
int CLinkList<T>::GetValue(T value)
{
	int j = 1;
	Node<T>* pNode = m_pHead;
	while ( pNode != NULL )
	{
		if (pNode->m_value == value)
		{
			return j;
		}
		j++;
		pNode = pNode->pNextNode;
	}
	// 没有找到
	return -1;
}

template <class T>
void CLinkList<T>::PrintList()
{
	Node<T>* pNode = m_pHead;
	while (pNode != NULL)
	{
		printf("%d\r\n", pNode->m_value);
		pNode = pNode->pNextNode;
	}
}

template <class T>
CLinkList<T>::~CLinkList()
{
	Node<T>* pNode = m_pHead;
	while (pNode != NULL)
	{
		Node<T>* r = pNode;
		pNode = pNode->pNextNode;
		delete r;
	}
	m_pHead = NULL;
}

template <class T>
void CLinkList<T>::Reverse()
{
	Node<T>* pPrev = NULL;
	Node<T>* pCur = m_pHead;
	while(pCur!=NULL && pCur->pNextNode != NULL)
	{
		Node<T>* next = pCur->pNextNode;
		pCur->pNextNode = pPrev;
		pPrev = pCur;
		pCur = next;
	}
	pCur->pNextNode = pPrev;
	m_pHead = pCur;
}

template <class T>
void CLinkList<T>::Ring()
{
	if (m_pHead == NULL)
	{
		return;
	}
	// 找到尾结点
	Node<T>* r = m_pHead;
	while (r->pNextNode != NULL)
	{
		r = r->pNextNode;
	}
	// 找到了尾结点,使其指向头结点
	r->pNextNode = m_pHead;
}

/*Node<T>* Recursion(Node<T>* pHead)
{
	if (pHead == NULL || pHead->pNextNode == NULL)
	{
		return pHead;
	}
	Node<T>* pNode = Recursion(pHead->pNextNode);
}*/
/*template <class T>
void CLinkList<T>::RecursionForReverse()
{

}*/

// 友元函数实现一元多项式求和
void Add(CLinkList<elem> & A, CLinkList<elem>& B)
{
	Node<elem>* pa = A.m_pHead;
	Node<elem>* pb = B.m_pHead;
	Node<elem>* pPrevA = NULL;
	Node<elem>* pPrevB = NULL;
	while (pa != NULL && pb != NULL)
	{
		// 如果A系数大于B, 将B元素插入到A当前元素的前边
		if (pa->m_value.exp > pb->m_value.exp)
		{
			Node<elem>* r = new Node<elem>;
			r->m_value.coef = pb->m_value.coef;
			r->m_value.exp = pb->m_value.exp;
			if (pa == A.m_pHead) // 头结点之前插入,要改变头指针
			{
				r->pNextNode = pa;
				A.m_pHead = r;
				pPrevA = r;
				pPrevB = pb;
				pb = pb->pNextNode;
			}else // 如果不是头指针
			{
				r->pNextNode = pa;
				pPrevA->pNextNode = r;
				pPrevA = r;
				pPrevB = pb;
				pb = pb->pNextNode;
			}
		}else if (pa->m_value.exp < pb->m_value.exp) // 如果A系数小于B,比较A下一个元素
		{
			pPrevA = pa;
			pa = pa->pNextNode;
		}else // 如果相等,求和
		{
			pa->m_value.coef += pb->m_value.coef;
			if (pa->m_value.coef == 0) // 如果系数为0,删除当前元素
			{
				if (pa == A.m_pHead) // 
				{
					A.m_pHead = pa->pNextNode;
					Node<elem>* s = pa;
					pa = pa->pNextNode;
					pPrevB = pb;
					pb = pb->pNextNode;
					delete s;
				}else
				{
					pPrevA->pNextNode = pa->pNextNode;
					pPrevA = pa;
					Node<elem>* s = pa;
					pa = pa->pNextNode;
					pPrevB = pb;
					pb = pb->pNextNode;
					delete s;
				}
			}else
			{
				pPrevA = pa;
				pPrevB = pb;
				pa = pa->pNextNode;
				pb = pb->pNextNode;
			}
		}
	}
	if (pb != NULL)
	{
		pPrevA->pNextNode = pb;
	}
}

void Circle(int n, int m)
{
	CLinkList<int> MyLinkList;
	for (int i = 1; i<=n; i++)
	{
		MyLinkList.Insert(i, i);
	}
	printf("报数:");
	MyLinkList.PrintList();
	// 环
	MyLinkList.Ring();
	printf("报%d出圈,出圈次序:", m);
	int k = m;
	Node<int>* pWork = MyLinkList.m_pHead;
	Node<int>* pPrev = pWork;
	for (int i = 0; i<n; i++)
	{
		while (--k)
		{
			pPrev = pWork;
			pWork = pWork->pNextNode;
		}
		k = m;
		printf("出圈%d, ", pWork->m_value);
		Node<int>* s = pWork;
		pPrev->pNextNode = pWork->pNextNode;
		pWork = pWork->pNextNode;
		delete s;
	}
	MyLinkList.m_pHead = NULL;
}

// 一些算法
// 1.设计一个时间复杂度为O(n)的算法,实现将数组A[n]中所有元素循环右移k个位置
template <class T>
void MoveArray(T array[], int nStart, int nEnd)
{
	while (nStart < nEnd)
	{
		T temp = array[nStart];
		array[nStart] = array[nEnd];
		array[nEnd] = temp;
		nStart++;
		nEnd--;
	}
}

template <class T>
void MoveArrayK(T array[], int nLen, int k)
{
	MoveArray(array, 0, nLen-1);
	MoveArray(array, 0, k-1);
	MoveArray(array, k, nLen-1);
}
// 2.已知数组A[n]的元素为整型,设计算法将其调整为左右两部分,左边所有元素为奇数,右边所有元素为偶数.
void DevisionOddAndEven(int array[], int nLen)
{
	// 设置两个标志位,分别指示数组头和尾;
	// 判断头元素是否为奇数
	// 是:组头标记前移;
	// 不是:将头元素与尾元素互换,尾元素前移.
	// 当头元素和尾元素标记重合,停止
	int nStart = 0;
	int nEnd = nLen - 1;
	while (nStart != nEnd)
	{
		if (array[nStart]%2 != 0)
		{
			nStart++;
		}else
		{
			int temp = array[nStart];
			array[nStart] = array[nEnd];
			array[nEnd] = temp;
			nEnd--;
		}
	}
}
// 3.1判断两个链表是否相交
template <class T>
bool TwoLinkIsIntersect(Node<T>* pHead1, Node<T>* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return false;
	}
	// 1.两个链表相交,它们的尾结点一定相同;所以分别找到两个链表的尾结点,判断值是否相等.
	Node* rear1 = pHead1;
	Node* rear2 = pHead2;
	while (rear1->pNextNode != NULL || rear2->pNextNode != NULL)
	{
		if (rear1->pNextNode != NULL)
		{
			rear1 = rear1->pNextNode;
		}
		if (rear2->pNextNode != NULL)
		{
			rear2 = rear2->pNextNode;
		}
	}
	if (*rear1 == *rear2)
	{
		return true;
	}
	return false;
}

// 3.2如果两个链表相交,找到它们第一个交点？
#endif // ZXP_LINKLIST_H_H