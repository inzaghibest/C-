// algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
/*1.把二元查找树转变成排序的双向链表
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
10
/ \
6 14
/ \ / \
4 8 12 16
转换成双向链表
4=6=8=10=12=14=16。*/
struct Node
{
	int m_nValue;
	Node* m_pLeftNode;
	Node* m_pRightNode;
};
/*2.设计包含min函数的栈。
定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
要求函数min、push以及pop的时间复杂度都是O(1)。*/
/* 思路

*/
#define MAX_LEN 1024
template <class T>
class CStack
{
private:
	vector<T> m_vtStack;
	T m_nMin; // 最小元素
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

/*3.求子数组的最大和
题目：
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。*/

/*5.查找最小的k个元素
题目：输入n个整数，输出其中最小的k个。
例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4。*/
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
		/* 如果累加和小于0,那么肯定不包括这个元素 */
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

