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
	int coef; // ϵ��
	int exp; // ָ��
};

template <class T>
class CLinkList
{
private:
	Node<T>* m_pHead;
	int m_nLength; // ��������
	// һԪ����ʽ���
	friend void Add(CLinkList<elem> & A, CLinkList<elem>& B);
public:
	friend void Circle(int n, int m);
	CLinkList();
	// ��ʼ������n��Ԫ��,ֵΪvalue�ĵ�����
	CLinkList(int n, T value);
	~CLinkList();
	// ��������
	int GetLength();
	// ɾ��������ĵ�i�����,����ɾ������ֵ
	T Delete(int i);
	// �ڵ������е�i��λ�ò���ֵΪx��Ԫ��
	void Insert(int i, T x);
	// ����ֵΪvalue�����
	int GetValue(T value);
	// ���ص�i��Ԫ�ص�ֵ
	T GetLocate(int i);
	// ���������
	void PrintList();
	// ����������
	void Reverse();
	// ��������ת���ɻ�,�˷���ʹ��֮��,ֻ��ʹ��Delete(i)����;�˷�����Ϊ�˽��Լɪ������
	void Ring();
	// �ݹ�ʵ�ֵ���������
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
	// ͷ�巨����������
	/*for (int i = 0; i<n; i++)
	{
		Node* pNode = new Node<T>;
		pNode->m_value = value;
		pNode->pNextNode = pHead;
		pHead = pNode;
	}*/
	// β�巨����������
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
	// ɾ���Ľ��
	return i;
}

template <class T>
T CLinkList<T>::Delete(int i)
{
	if (i == 0)
	{
		CError error("ɾ��λ���쳣");
		throw error;
	}
	// ͷָ��ɾ��
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
		CError error("����δ��ʼ��");
		throw error;
	}
	// r��Ҫɾ���Ľ��,prev��ǰ�ý��
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
		CError error("����λ���쳣!");
		throw  error;
	}
	if (m_pHead == NULL)
	{
		m_pHead = new Node<T>;
		m_pHead->m_value = x;
		m_pHead->pNextNode = NULL;
		return;
	}
	// Ѱ�Ҳ�����
	Node<T>* r = m_pHead;
	Node<T>* prev = m_pHead;
	while (--i && r!=NULL)
	{
		prev = r;
		r=r->pNextNode;
	}
	if (r == NULL) // ���������Ϊ���ڶ�β
	{
		r = new Node<T>;
		r->m_value = x;
		r->pNextNode = NULL;
		prev->pNextNode = r;
		return;
	}
	// �������ͷ������,��ͷָ��ָ��������,��������һ��Ϊԭ����ͷָ��
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
		CError error("����λ�÷Ƿ�");
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
	// û���ҵ�
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
	// �ҵ�β���
	Node<T>* r = m_pHead;
	while (r->pNextNode != NULL)
	{
		r = r->pNextNode;
	}
	// �ҵ���β���,ʹ��ָ��ͷ���
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

// ��Ԫ����ʵ��һԪ����ʽ���
void Add(CLinkList<elem> & A, CLinkList<elem>& B)
{
	Node<elem>* pa = A.m_pHead;
	Node<elem>* pb = B.m_pHead;
	Node<elem>* pPrevA = NULL;
	Node<elem>* pPrevB = NULL;
	while (pa != NULL && pb != NULL)
	{
		// ���Aϵ������B, ��BԪ�ز��뵽A��ǰԪ�ص�ǰ��
		if (pa->m_value.exp > pb->m_value.exp)
		{
			Node<elem>* r = new Node<elem>;
			r->m_value.coef = pb->m_value.coef;
			r->m_value.exp = pb->m_value.exp;
			if (pa == A.m_pHead) // ͷ���֮ǰ����,Ҫ�ı�ͷָ��
			{
				r->pNextNode = pa;
				A.m_pHead = r;
				pPrevA = r;
				pPrevB = pb;
				pb = pb->pNextNode;
			}else // �������ͷָ��
			{
				r->pNextNode = pa;
				pPrevA->pNextNode = r;
				pPrevA = r;
				pPrevB = pb;
				pb = pb->pNextNode;
			}
		}else if (pa->m_value.exp < pb->m_value.exp) // ���Aϵ��С��B,�Ƚ�A��һ��Ԫ��
		{
			pPrevA = pa;
			pa = pa->pNextNode;
		}else // ������,���
		{
			pa->m_value.coef += pb->m_value.coef;
			if (pa->m_value.coef == 0) // ���ϵ��Ϊ0,ɾ����ǰԪ��
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
	printf("����:");
	MyLinkList.PrintList();
	// ��
	MyLinkList.Ring();
	printf("��%d��Ȧ,��Ȧ����:", m);
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
		printf("��Ȧ%d, ", pWork->m_value);
		Node<int>* s = pWork;
		pPrev->pNextNode = pWork->pNextNode;
		pWork = pWork->pNextNode;
		delete s;
	}
	MyLinkList.m_pHead = NULL;
}

// һЩ�㷨
// 1.���һ��ʱ�临�Ӷ�ΪO(n)���㷨,ʵ�ֽ�����A[n]������Ԫ��ѭ������k��λ��
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
// 2.��֪����A[n]��Ԫ��Ϊ����,����㷨�������Ϊ����������,�������Ԫ��Ϊ����,�ұ�����Ԫ��Ϊż��.
void DevisionOddAndEven(int array[], int nLen)
{
	// ����������־λ,�ֱ�ָʾ����ͷ��β;
	// �ж�ͷԪ���Ƿ�Ϊ����
	// ��:��ͷ���ǰ��;
	// ����:��ͷԪ����βԪ�ػ���,βԪ��ǰ��.
	// ��ͷԪ�غ�βԪ�ر���غ�,ֹͣ
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
// 3.1�ж����������Ƿ��ཻ
template <class T>
bool TwoLinkIsIntersect(Node<T>* pHead1, Node<T>* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return false;
	}
	// 1.���������ཻ,���ǵ�β���һ����ͬ;���Էֱ��ҵ����������β���,�ж�ֵ�Ƿ����.
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

// 3.2������������ཻ,�ҵ����ǵ�һ�����㣿
#endif // ZXP_LINKLIST_H_H