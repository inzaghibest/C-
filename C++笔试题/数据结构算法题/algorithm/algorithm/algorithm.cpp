// algorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;
/*1.�Ѷ�Ԫ������ת��������˫������
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
10
/ \
6 14
/ \ / \
4 8 12 16
ת����˫������
4=6=8=10=12=14=16��*/
struct Node
{
	int m_nValue;
	Node* m_pLeftNode;
	Node* m_pRightNode;
};
/*2.��ư���min������ջ��
����ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�
Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)��*/
/* ˼·

*/
#define MAX_LEN 1024
template <class T>
class CStack
{
private:
	vector<T> m_vtStack;
	T m_nMin; // ��СԪ��
public:
	CStack():m_nMin(0){}
	void push(T nValue);
	T pop();
	T min();
};

template <class T>
T CStack<T>::min()
{
	return m_nMin;
}

template <class T>
void CStack<T>::push(T nValue)
{
	if (m_vtStack.empty())
	{
		m_vtStack.push_back(0);
		m_nMin = nValue;
		return;
	}
	T diff = nValue - m_nMin;
	m_vtStack.push_back(diff);
	if (diff < 0)
	{
		m_nMin = nValue;
	}
	return;
}

template <class T>
T CStack<T>::pop()
{
	if (!m_vtStack.empty())
	{
		T diff = m_vtStack.back();
		T value =  0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ;
		if (diff >= 0)
		{
			m_vtStack.pop_back();
			value =  diff + m_nMin;
		}else
		{
			value = m_nMin;
			m_nMin  -= diff;
			m_vtStack.pop_back();
		}
		return value;
	}
}

/*3.�������������
��Ŀ��
����һ���������飬������������Ҳ�и�����
������������һ�������������һ�������飬ÿ�������鶼��һ���͡�
������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
�������������Ϊ1, -2, 3, 10, -4, 7, 2, -5��������������Ϊ3, 10, -4, 7, 2��
������Ϊ��������ĺ�18��*/

/*5.������С��k��Ԫ��
��Ŀ������n�����������������С��k����
��������1��2��3��4��5��6��7��8��8�����֣�����С��4������Ϊ1��2��3��4��*/
void GetManyMin(int array[], int n, int nCount)
{
	for (int i = 0; i<n; i++)
	{

	}
}
void ReverseString(char szArray[])
{
	if (szArray == NULL)
	{
		return;
	}

}
int GetMaxChildArrayFromArray(int array[], int n, int& nStart, int& nEnd)
{
	int nThisMax = 0;
	int nCurValue = 0;
	bool bRestart = false;
	nStart = 0;
	for (int i = 0; i<n; i++)
	{
		nCurValue += array[i];
		if (nCurValue > nThisMax)
		{
			if (bRestart)
			{
				nStart = i;
				bRestart = false;
			}
			nThisMax = nCurValue;
			nEnd = i;
		}
		/* ����ۼӺ�С��0,��ô�϶����������Ԫ�� */
		if (nCurValue < 0)
		{
			bRestart = true;
			nCurValue = 0;
		}
	}
	return nThisMax;
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*CStack<int> MyStack;
	MyStack.push(3);
	MyStack.push(2);
	MyStack.push(7);
	MyStack.push(-1);
	MyStack.push(4);
	for (int i = 0;i<5;i++)
	{
		printf("MyStack Min:%d\r\n", MyStack.min());
		MyStack.pop();
	}*/

	int array[] = {1, -2, 3, 10,-10, -4, 7, 2, -5};
	for (int i = 0; i<sizeof(array)/sizeof(int); i++)
	{
		printf("%d ,", array[i]);
	}
	int nStart = 0;
	int nEnd = 0;
	int nMax = GetMaxChildArrayFromArray(array, sizeof(array)/sizeof(int), nStart, nEnd);
	printf("Max : %d\r\n Start = %d\r\n End = %d\r\n", nMax, nStart, nEnd);
	getchar();
	return 0;
}

