// StackQueueAndString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "zxp_stack.h"
#include "zxp_queue.h"
#include "zxp_string.h"
int _tmain(int argc, _TCHAR* argv[])
{
	// ����ջ����
	/*CBothStack<int> bothStack;
	for (int i = 0; i<5; i++)
	{
		bothStack.Push(1,i);
		bothStack.Push(2,i);
	}
	bothStack.PrintStack();*/
	// ��ջ����
	/*CLinkStack<int> linkStack;
	for (int i = 0; i<10; i++)
	{
		linkStack.Push(i);
	}
	for (int j = 0; j<10;j++)
	{
		int nValue = linkStack.Pop();
		printf("%d, ", nValue);
	}*/
	// ѭ�����в���
	/*CCirQueue<int> MyCirQueue;
	for (int i = 0; i<9; i++)
	{
		MyCirQueue.EnQueue(i);
		if ((i != 0) && (i % 3) == 0)
		{
			MyCirQueue.DeQueue();
		}
	}
	while (!MyCirQueue.Empty())
	{
			printf("%d, ", MyCirQueue.DeQueue());
	}*/

	// �����в���
	/*CLinkQueue<int> MyLinkQueue;
	for (int i = 0; i<15; i++)
	{
		MyLinkQueue.EnQueue(i);
	}
	while (!MyLinkQueue.Empty())
	{
			printf("%d, ",MyLinkQueue.DeQueue());
	}
	for (int i = 0; i<15; i++)
	{
		MyLinkQueue.EnQueue(i);
	}*/

	// ����ģʽƥ���㷨����
	/*char S[] = "abcdekdefgh";
	char T[] = "def";
	int n = BF(S, T);
	printf("%d\r\n", n);*/


	// KMP�㷨����
	int i;
	int next[20]={0};
	char T[] = "ababxbababcadfdsss";
	char P[] = "abcad";
	printf("%s\n",T);
	printf("%s\n",P );
	makeNext(P,next);
	kmp(T,P,next);
	for (i = 0; i < strlen(P); ++i)
	{
			 printf("%d ",next[i]);
	}
	printf("\n");
	getchar();
	return 0;
}

